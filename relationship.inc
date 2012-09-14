<?php

class Relationship extends Individual {
  protected $entity = 'relationship'; // this is the default
  protected $debug = 0;
  protected $keyField = 'person_organization_id';
  protected $description = "Relationship Types";
  public function __construct() {
    parent::__construct(1);
    $this->softDependencies = array('Individual','Organisation','RelationshipTypes');
      $this->addFieldMapping('contact_id_a','person_ref')->sourceMigration('Individual');
      $this->addFieldMapping('contact_id_b','organization_ref')->sourceMigration('Organisation');
      $this->addFieldMapping('relationship_type_id','affiliation_id')->sourceMigration('RelationshipTypes');
  }
  function prepareRow($current_row){
    if ($current_row->CONNECTION_TYPE == 'Start Date'
    || $current_row->CONNECTION_TYPE == 'N/A'
    || $current_row->CONNECTION_TYPE == 'National Access'
    || empty($current_row->CONNECTION_TYPE)){
      return false;
    }
    return true;
  }
  function prepare(&$entity, &$row){
    if($entity->is_active == 'Inactive'){
      $entity->is_active = 0;
    }
    else{
      $entity->is_active = 1;
    }
    if(empty($entity->id)){
      $getParams = (array) $entity;
      $getParams['version'] = 3;
      unset($getParams['is_active']);
      if(empty($getParams['end_date'])){
        unset($getParams['end_date']);
      }
      if(empty($getParams['start_date'])){
        unset($getParams['start_date']);
      }
      drupal_set_message("<pre>" . print_r($getParams,1) . "</pre>");
      $rels = civicrm_api('relationship', 'get', $getParams);
      drupal_set_message("<pre>" . print_r($rels,1) . "</pre>");
      if(!empty($rels['id'])){
        $entity->id = $rels['id'];
      }
    }
  }
}