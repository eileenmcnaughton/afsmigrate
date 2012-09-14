<?php
class OGSophia extends Civimigration {

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
    $this->softDependencies = array('AFSDrupalUser');
    $this->map = new MigrateSQLMap($this->machineName,
        array(
            'id' => array(
                'type' => 'int',
                'not null' => TRUE,
                'description' => 'inique  ID in groupmembers table to allow rollback.',
                'alias' => 'rel',
            )
        ),
        MigrateDestinationOGMembership::getKeySchema()
    );

    $query = db_select($this->civiDBPrefix .'civicrm_relationship', 'rel')
      ->fields('rel', array('contact_id_a','id', 'start_date','end_date', 'is_active'))
      ->condition('relationship_type_id' ,'23')

     ;
     $query->join($this->civiDBPrefix. 'civicrm_uf_match', 'uf', 'uf.contact_id = rel.contact_id_a');
     $query->fields( 'uf', array('uf_id'));

     $this->source = new MigrateSourceSQL($query);

    // Set up our destination
    $this->destination = new MigrateDestinationOGMembership();
//127 = 23 (treasuers)
//115 = Presidents
    // Mapped fields:
    $this->addFieldMapping('gid')->defaultValue(127);

    $this->addFieldMapping('is_active', 'is_active')->defaultValue(1);
    $this->addFieldMapping('uid', 'uf_id');
    $this->addFieldMapping('is_admin')->defaultValue(0);

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array('created'));
  }
  function prepareRow(&$current_row){
    if(!empty($current_row->end_date)){
      if(strtotime($current_row->end_date) < strtotime('now')){
        if(empty($current_row->migrate_map_destid2)){
          return false;
        }
        $current_row->is_active = 0;
      }
    }
    return true;
  }
  function prepare(&$entity,&$row){
  }
}