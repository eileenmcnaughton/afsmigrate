<?php

class OrganisationFax extends Individual {

  protected $entity = 'phone';
  protected $debug = 0;
  protected $keyField = 'organization_ref';
  protected $description = "Organisation phone";
  public function __construct() {
    parent::__construct(1);
    $this->softDependencies = array('Organisation');
    $this->addFieldMapping('contact_id','organization_ref')
      ->sourceMigration('Organisation');
  }
  function prepareRow($current_row){
    if (empty($current_row->MAIN_ORG_FAXNUM)){
      return false;
    }
    return true;
  }

}