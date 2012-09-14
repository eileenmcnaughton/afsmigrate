<?php

class IndividualEmail2 extends Individual {

  protected $entity = 'email';
  protected $debug = 0;
  protected $keyField = 'person_ref';
  protected $description = "Individual Emails 2";

  public function __construct() {
    parent::__construct(1);
    $this->softDependencies = array('Individual');
    $this->addFieldMapping('contact_id','person_ref')->sourceMigration('Individual');
  }
  function prepareRow($current_row){
    if (empty($current_row->preferred_email_two)){
      return false;
    }
    return true;
  }

  function prepare(&$entity, &$row){
   if(empty($entity->id)){
    $existing = civicrm_api('email', 'get', array(
    'version' => 3,
    'location_type_id' => 4,
     'email' => $entity->email,
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
}