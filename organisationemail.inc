<?php

class OrganisationEmail extends Individual {

  protected $entity = 'email';
  protected $debug = 0;
  protected $keyField = 'organization_ref';
  protected $description = "Organisation email";
  public function __construct() {
    parent::__construct(1);
    $this->softDependencies = array('Organisation');
    $this->addFieldMapping('contact_id','organization_ref')
      ->sourceMigration('Organisation');
  }
  function prepareRow($current_row){

    if (empty($current_row->main_org_email)){
      return false;
    }

    return true;
  }
  function prepare(&$entity, &$row){
    $this->mergeemail($entity, $row, 7);
  }
}
