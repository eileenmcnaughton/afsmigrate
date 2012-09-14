<?php

class OrganisationWebsite extends Individual {

  protected $entity = 'website';
  protected $debug = 0;
  protected $keyField = 'organization_ref';
  protected $description = "Organisation website";
  public function __construct() {
    parent::__construct(1);
    $this->softDependencies = array('Organisation');
    $this->addFieldMapping('contact_id','organization_ref')
      ->sourceMigration('Organisation');
  }
  function prepareRow($current_row){
    if (empty($current_row->MAIN_ORG_WEB_SITE)){
      return false;
    }
    return true;
  }
  function prepare(&$entity, &$row){
    $this->mergewebsite($entity, $row);
    if(!strstr('http', $entity->website)){
      $entity->website = "http://" . $entity->website;
    }
  }
}