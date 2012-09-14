<?php

class OrganisationAddress extends Individual {

  protected $entity = 'address';
  protected $debug = 0;
  protected $keyField = 'organization_ref';
  protected $description = "Organisation address";
  public function __construct() {
    parent::__construct(1);
    $this->softDependencies = array('Organisation');
    $this->addFieldMapping('contact_id','organization_ref')
      ->sourceMigration('Organisation');
  }
  function prepareRow($current_row){
    if (empty($current_row->main_org_english_address1)){
      return false;
    }
    return true;
  }

  function prepare(&$entity, &$row){
    $this->mergeaddress($entity, $row, 7);
  }
}