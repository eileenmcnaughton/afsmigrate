<?php

class Organisation extends Individual {
  protected $entity = 'contact'; // this is the default
  protected $debug = 0;
  protected $matchexternalidentifier = 1;
  protected $keyField = 'organization_ref';
  protected $description = 'Organisation';

  public function __construct() {

    parent::__construct(1);
  }

  function prepareRow($current_row){
    if (empty($current_row->organization_ref)){
      return false;
    }
    return true;
  }

  function prepare(&$entity,&$row){
    $entity->external_identifier = 'O-' .$entity->external_identifier;
    $result = civicrm_api('Contact','get',array('version' => 3, 'external_identifier' =>  $entity->external_identifier));
    if(CRM_Utils_Array::value('id',$result)){
      $entity->id = $result['id'];
    }
    $result = civicrm_api('Contact','get',array('version' => 3, 'contact_type' => 'Organization','organization_name' => $entity->organization_name));

	if(CRM_Utils_Array::value('id',$result)){
      $entity->id = $result['id'];
    }
    switch ($entity->contact_sub_type){
      case 'AFS Chapter':
        $entity->contact_sub_type = 'AFS_Chapter';
        break;
      case 'AFS Partner':
        $entity->contact_sub_type = 'AFS_Partner';
        break;
      case 'School':
        $entity->contact_sub_type = 'Schools';
        break;
      case 'Outside Organization':
        $entity->contact_sub_type = 'Outside_Organisation';
        break;
      case 'Other Organization':
        $entity->contact_sub_type = 'Other_Organisation';
        break;
      case 'AFS National Office':
      case 'AFS National Board':
        unset($entity->contact_sub_type );
        break;
    }

  }

}