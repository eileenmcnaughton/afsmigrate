<?php

class Individual extends Civimigration {
  protected $base_table = '';
  protected $base_table_id = '';
  protected $autoquery = 1;
  protected $entity = 'contact'; // this is the default
  protected $debug = 0;
  protected $matchexternalidentifier = 1;
  protected $description = 'Contact data - main import';
  protected $keyField = 'person_ref';

  public function __construct($child = 0) {
    parent::__construct();

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          $this->keyField => array(
            'type' => 'varchar',
            'length' => 100,
            'not null' => TRUE,
           )
        ),
        MigrateDestinationTerm::getKeySchema()
      );

      $columns = $this->getcsvMappings();
      // Instantiate the class using the path to the CSV file and the columns.
      $this->source = new MigrateSourceCSV('sites/afs.org.nz/files/civicrm/afsupload.csv',
        $columns,
        array('header_rows' => 1)
      );

  }

  function prepare(&$entity, &$row){
    if($row->CONNECTION_TYPE == 'Start Date'){
      $entity->custom_68 = $row->ORG_LINK_FROM_DATE;
    }
  }
  /*
   * Look up existing mail & take it over if it matches
   */
  function mergeemail(&$entity, &$row, $location){
    if(empty($entity->id)){
      $existing = civicrm_api('email', 'get', array(
          'version' => 3,
          'location_type_id' => $location,
          'contact_id' => $entity->contact_id,
          'options' => array('limit' => 1)));
      if(!empty($existing['id'])){
        $entity->id = $existing['id'];
      }else{
        $existing = civicrm_api('email', 'get', array(
          'version' => 3,
          'email' => $entity->email,
          'contact_id' => $entity->contact_id,
          'options' => array('limit' => 1))
        );
        if(!empty($existing['id'])){
          $entity->id = $existing['id'];
        }
      }
    }
  }

  /*
   * Look up existing mail & take it over if it matches
  */
  function mergeaddress(&$entity, &$row, $location){
    if(empty($entity->id)){
      $existing = civicrm_api('address', 'get', array(
          'version' => 3,
          'location_type_id' => $location,
          'contact_id' => $entity->contact_id,
          'options' => array('limit' => 1)));
      if(!empty($existing['id'])){
        $entity->id = $existing['id'];
      }else{
        $existing = civicrm_api('address', 'get', array(
            'version' => 3,
            'street_address' => $entity->street_address,
            'contact_id' => $entity->contact_id,
            'options' => array('limit' => 1))
        );
        if(!empty($existing['id'])){
          $entity->id = $existing['id'];
        }
      }
    }
  }

  /*
   * Look up existing website & take it over if it matches
  */
  function mergewebsite(&$entity, &$row){
    if(empty($entity->id)){
      $existing = civicrm_api('website', 'get', array(
          'version' => 3,
          'website' => $entity->website,
          'contact_id' => $entity->contact_id,
          'options' => array('limit' => 1)));
      if(!empty($existing['id'])){
        $entity->id = $existing['id'];
      }
    }
  }

  function getcsvMappings(){
    return array(
       array('person_ref', 'external identifier'),
       array('ENGLISH_FIRSTNAME', 'ENGLISH_FIRSTNAME'),
       array('ENGLISH_LASTNAME', 'ENGLISH_LASTNAME'),
       array('ENGLISH_NICKNAME', 'ENGLISH_NICKNAME'),
       array('DATE_OF_BIRTH', 'birth date'),
       array('mailing_address', 'MAILING_ADDRESS'),
       array('ENGLISH_ZIP', 'ENGLISH_ZIP'),
       array('preferred_email', 'PREFERRED_EMAIL'),
       array('preferred_email_two', 'preferred_email_two'),
       array('SEX', 'gender'),
       array('TITLE', 'prefix'),
       array('work_email','work_email'),
       array('WORK_FAX','WORK_FAX'),
       array('WORK_TELEPHONE','WORK_TELEPHONE'),
       array('INSTANT_MESSAGE_ADDRESS','INSTANT_MESSAGE_ADDRESS'),
       array('COUNTRY','COUNTRY'),
       array('ENGLISH_ADDRESS1','ENGLISH_ADDRESS1'),
       array('ENGLISH_ADDRESS2','ENGLISH_ADDRESS2'),
       array('ENGLISH_CITY', 'ENGLISH_CITY'),
       array('PERSON_ID','PERSON_ID'),
       array('NATIVE_TITLE','NATIVE_TITLE'),
       array('NATIVE_FIRSTNAME','NATIVE_FIRSTNAME'),
       array('NATIVE_LASTNAME','NATIVE_LASTNAME'),
       array('NATIVE_NICKNAME','NATIVE_NICKNAME'),
       array('NATIVE_ADDRESS1','NATIVE_ADDRESS1'),
       array('NATIVE_ADDRESS2','NATIVE_ADDRESS2'),
       array('NATIVE_CITY','NATIVE_CITY'),
       array('NATIVE_ZIP','NATIVE_ZIP'),
       array('MAIN_ORG_ID','MAIN_ORG_ID'),
       array('ORG_LINK_FROM_DATE','ORG_LINK_FROM_DATE'),
       array('ORG_LINK_TO_DATE','ORG_LINK_TO_DATE'),
       array('STATUS','STATUS'),
       array('PERSON_ROLE','PERSON_ROLE'),
       array('affiliation_id','affiliation_id'),
       array('AFFILIATION_TYPE','AFFILIATION_TYPE'),
       array('CONNECTION_TYPE','CONNECTION_TYPE'),
       array('GL_AFFILIATION','GL_AFFILIATION'),
       array('organization_ref','organization_ref'),
       array('ORG_TYPE','ORG_TYPE'),
       array('ORGANIZATION_ID_FOR_PL19','ORGANIZATION_ID_FOR_PL19'),
       array('MAIN_ORG_NAME','MAIN_ORG_NAME'),
       array('MAIN_ORG_NATIVE_NAME','MAIN_ORG_NATIVE_NAME'),
       array('MAIN_ORG_CHAPTER','MAIN_ORG_CHAPTER'),
       array('MAIN_ORG_CHAPTER_ID','MAIN_ORG_CHAPTER_ID'),
       array('MAIN_ORG_CONTACT_NAME','MAIN_ORG_CONTACT_NAME'),
       array('MAIN_ORG_COUNTRY','MAIN_ORG_COUNTRY'),
       array('main_org_english_address1','main_org_english_address1'),
       array('MAIN_ORG_ENGLISH_ADDRESS2','MAIN_ORG_ENGLISH_ADDRESS2'),
       array('MAIN_ORG_ENGLISH_CITY','MAIN_ORG_ENGLISH_CITY'),
       array('MAIN_ORG_ENGLISH_ZIP','MAIN_ORG_ENGLISH_ZIP'),
       array('MAIN_ORG_ENGLISH_STATE','MAIN_ORG_ENGLISH_STATE'),
       array('MAIN_ORG_NATIVE_ADDRESS1','MAIN_ORG_NATIVE_ADDRESS1'),
       array('MAIN_ORG_NATIVE_ADDRESS2','MAIN_ORG_NATIVE_ADDRESS2'),
       array('MAIN_ORG_NATIVE_CITY','MAIN_ORG_NATIVE_CITY'),
       array('MAIN_ORG_NATIVE_STATE','MAIN_ORG_NATIVE_STATE'),
       array('MAIN_ORG_NATIVE_ZIP','MAIN_ORG_NATIVE_ZIP'),
       array('main_org_email','main_org_email'),
       array('MAIN_ORG_FAXNUM','MAIN_ORG_FAXNUM'),
       array('NATIVE_ORG_SUB_TYPE','NATIVE_ORG_SUB_TYPE'),
       array('MAIN_ORG_WEB_SITE','MAIN_ORG_WEB_SITE'),
       array('ORG_STATUS','ORG_STATUS'),
       array('person_organization_id','person_organization_id'),
    );
  }
}
/*
 *
REPLACE INTO `autoload_registry` (`name`, `type`, `filename`, `module`, `weight`) VALUES ('Organisation', 'class', 'sites/afs.org.nz/modules/afsmigrate/organisation.inc', 'afsmigrate', 0);
REPLACE INTO `autoload_registry` (`name`, `type`, `filename`, `module`, `weight`) VALUES ('IndividualFax', 'class', 'sites/afs.org.nz/modules/afsmigrate/individualfax.inc', 'afsmigrate', 0);
REPLACE INTO `autoload_registry` (`name`, `type`, `filename`, `module`, `weight`) VALUES ('OrganisationAddress', 'class', 'sites/afs.org.nz/modules/afsmigrate/organisationaddress.inc', 'afsmigrate', 0);
REPLACE INTO `autoload_registry` (`name`, `type`, `filename`, `module`, `weight`) VALUES ('OrganisationEmail', 'class', 'sites/afs.org.nz/modules/afsmigrate/organisationemail.inc', 'afsmigrate', 0);
REPLACE INTO `autoload_registry` (`name`, `type`, `filename`, `module`, `weight`) VALUES ('OrganisationFax', 'class', 'sites/afs.org.nz/modules/afsmigrate/organisationfax.inc', 'afsmigrate', 0);
REPLACE INTO `autoload_registry` (`name`, `type`, `filename`, `module`, `weight`) VALUES ('OrganisationWebsite', 'class', 'sites/afs.org.nz/modules/afsmigrate/organisationwebsite.inc', 'afsmigrate', 0);
REPLACE INTO `autoload_registry` (`name`, `type`, `filename`, `module`, `weight`) VALUES ('IndividualPhone', 'class', 'sites/afs.org.nz/modules/afsmigrate/individualphone.inc', 'afsmigrate', 0);
REPLACE INTO `autoload_registry` (`name`, `type`, `filename`, `module`, `weight`) VALUES ('IndividualFax', 'class', 'sites/afs.org.nz/modules/afsmigrate/individualfax.inc', 'afsmigrate', 0);
REPLACE INTO `autoload_registry` (`name`, `type`, `filename`, `module`, `weight`) VALUES ('Relationship', 'class', 'sites/afs.org.nz/modules/afsmigrate/relationship.inc', 'afsmigrate', 0);
REPLACE INTO `autoload_registry` (`name`, `type`, `filename`, `module`, `weight`) VALUES ('RelationshipTypes', 'class', 'sites/afs.org.nz/modules/afsmigrate/relationshiptypes.inc', 'afsmigrate', 0);*/