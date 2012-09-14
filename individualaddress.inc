<?php

class IndividualAddress extends Individual {

  protected $entity = 'address';
  protected $debug = 0;
  protected $keyField = 'person_ref';
  protected $description = "Individual address";
  public function __construct() {
    parent::__construct(1);
    $this->softDependencies = array('Individual');
    $this->addFieldMapping('contact_id','person_ref')
      ->sourceMigration('Individual');
  }
  function prepareRow($current_row){
    if (empty($current_row->mailing_address)){
     // return false;
    }
    return true;
  }

  function prepare(&$entity, &$row){
    $this->mergeaddress($entity, $row, 7);
  }

}