<?php
class AFSDrupalUser extends Civimigration {

  protected $base_table_id = 'id';
  protected $base_table_alias = 'rel';
  protected $autoquery = 1;
  protected $debug = 1;
  protected $entity = 'contact'; // this is the default
  protected $description = 'Contact data - main import';
  protected $civiDBPrefix = 'afs.';
  protected $base_table = 'afs.civicrm_relationship';
  public function __construct($child = 0) {
    parent::__construct();
    $this->softDependencies = array('Individual');
    $this->map = new MigrateSQLMap($this->machineName,
        array(
            'id' => array(
                'type' => 'int',
                'not null' => TRUE,
                'description' => 'inique  ID in groupmembers table to allow rollback.',
                'alias' => 'rel',
            )
        ),
        MigrateDestinationUser::getKeySchema()
    );

    $query = db_select($this->civiDBPrefix .'civicrm_relationship', 'rel')
      ->fields('rel', array('start_date','end_date', 'is_active', 'id'))
      ->condition('relationship_type_id' ,'23')
      ->isNull('end_date');

     $query->leftjoin($this->civiDBPrefix. 'civicrm_uf_match', 'uf', 'uf.contact_id = rel.contact_id_a');
     $query->isNull('uf_id');

     $query->fields( 'uf', array('uf_id'));
     $query->join($this->civiDBPrefix. 'civicrm_email', 'email', 'email.contact_id = rel.contact_id_a AND email.is_primary = 1');
     $query->fields( 'email', array('email'));
     $query->join($this->civiDBPrefix. 'civicrm_contact', 'contact', 'contact.id = rel.contact_id_a AND contact.is_deleted = 0');
     $query->addExpression("LOWER(CONCAT(first_name, '.',last_name))",'username');
     $this->source = new MigrateSourceSQL($query);

    // Set up our destination
    $this->destination = new MigrateDestinationUser();
//127 = 23 (treasuers)
//115 = Presidents
    $this->addFieldMapping('status', 'is_active');
    $this->addFieldMapping('mail', 'email');
    // Our source table has two entries for 'alice', but we must have a unique
    // username in the Drupal 'users' table. dedupe() creates new, unique
    // destination values when the source field of that value already exists.
    // For example, if we're importing a user with name 'test' and a user
    // 'test' already exists in the target, we'll create a new user named
    // 'test_1'.
    // dedupe() takes the Drupal table and column for determining uniqueness.
    $this->addFieldMapping('name', 'username')
         ->dedupe('users', 'name');

    // The migrate module automatically converts date/time strings to UNIX timestamps.
 //   $this->addFieldMapping('created', 'posted');

    $this->addFieldMapping('pass', 'last_name');

    // Instead of mapping a source field to a destination field, you can
    // hardcode a default value. You can also use both together - if a default
    // value is provided in addition to a source field, the default value will
    // be applied to any rows where the source field is empty or NULL.
    $this->addFieldMapping('roles')
         ->defaultValue(DRUPAL_AUTHENTICATED_RID);


    // Unmapped destination fields

    // This is a shortcut you can use to mark several destination fields as DNM
    // at once
    $this->addUnmigratedDestinations(array('theme', 'signature', 'access', 'login',
      'timezone', 'language', 'picture', 'role_names'));
  }

  public function prepare(&$entity,&$row){

  }
}