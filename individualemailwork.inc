<?php

class IndividualEmailWork extends Individual {

  protected $entity = 'email';
  protected $debug = 0;
  protected $keyField = 'person_ref';
  protected $description = "Individual Emails Work";

  public function __construct() {
    parent::__construct(1);
    $this->softDependencies = array('Individual');
    $this->addFieldMapping('contact_id','person_ref')->sourceMigration('Individual');
  }
  function prepareRow($current_row){
    if (empty($current_row->work_email)){
      return false;
    }
    return true;
  }

  function prepare(&$entity, &$row){
    $this->mergeemail($entity, $row, 8);
  }
}