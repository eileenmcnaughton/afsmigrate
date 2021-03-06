<?php

class IndividualFax extends Individual {

  protected $entity = 'phone';
  protected $debug = 0;
  protected $keyField = 'person_ref';
  protected $description = "Individual fax";

  public function __construct() {
    parent::__construct(1);
    $this->softDependencies = array('Individual');
    $this->addFieldMapping('contact_id','person_ref')->sourceMigration('Individual');
  }
  function prepareRow($current_row){

    if (empty($current_row->fax)){
      return false;
    }
    return true;
  }

}