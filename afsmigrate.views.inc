<?php
function afsmigrate_views_data() {
  $tables = array();
  $tables['migrate_map_individuals']['table']['join']['feeds_data_gl_individuals'] = array(
    'left_field' => 'person_ref',
    'field' => 'sourceid',
  );
  $tables['migrate_map_indiv_address']['table']['join']['feeds_data_gl_individuals'] = array(
    'left_field' => 'person_ref',
    'field' => 'sourceid',
  );
  $tables['migrate_map_indiv_phone']['table']['join']['feeds_data_gl_individuals'] = array(
    'left_field' => 'person_ref',
    'field' => 'sourceid',
  );
    $tables['migrate_map_indiv_fax']['table']['join']['feeds_data_gl_individuals'] = array(
    'left_field' => 'person_ref',
    'field' => 'sourceid',
  );
  $tables['migrate_map_email2_indiv']['table']['join']['feeds_data_gl_individuals'] = array(
    'left_field' => 'person_ref',
    'field' => 'sourceid',
  );
    $tables['migrate_map_indiv_work_email']['table']['join']['feeds_data_gl_individuals'] = array(
    'left_field' => 'person_ref',
    'field' => 'sourceid',
  );
    $tables['migrate_map_indiv_prim_email']['table']['join']['feeds_data_gl_individuals'] = array(
    'left_field' => 'person_ref',
    'field' => 'sourceid',
  );
  $tables['migrate_map_create_orgs']['table']['join']['feeds_data_gl_orgs'] = array(
    'left_field' => 'organization_ref',
    'field' => 'sourceid',
  );
    $tables['migrate_map_org_email']['table']['join']['feeds_data_gl_orgs'] = array(
    'left_field' => 'organization_ref',
    'field' => 'sourceid',
  );
      $tables['migrate_map_org_address']['table']['join']['feeds_data_gl_orgs'] = array(
    'left_field' => 'organization_ref',
    'field' => 'sourceid',
  );
   $tables['migrate_map_org_website']['table']['join']['feeds_data_gl_orgs'] = array(
    'left_field' => 'organization_ref',
    'field' => 'sourceid',
  );
    $tables['migrate_map_org_fax']['table']['join']['feeds_data_gl_orgs'] = array(
    'left_field' => 'organization_ref',
    'field' => 'sourceid',
  ); 
   $tables['feeds_data_gl_orgs']['table']['join']['migrate_map_create_orgs'] = array(
    'field' => 'organization_ref',
    'left_field' => 'sourceid',
  ); 
  $tables['migrate_map_individuals']['table']['join']['feeds_data_gl_relationships'] = array(
    'left_field' => 'person_ref',
    'field' => 'sourceid',
  );
  $tables['migrate_map_reltypes']['table']['join']['feeds_data_gl_reltypes'] = array(
    'left_field' => 'affiliation_id',
    'field' => 'sourceid',
  );
    $tables['migrate_map_reltypes']['table']['join']['feeds_data_gl_relationships'] = array(
    'left_field' => 'affiliation_id',
    'field' => 'sourceid',
  );
  $tables['migrate_map_create_orgs']['table']['join']['feeds_data_gl_relationships'] = array(
    'left_field' => 'organization_ref',
    'field' => 'sourceid',
  );

  $tables['migrate_map_relationship']['table']['join']['feeds_data_gl_relationships'] = array(
    'left_field' => 'person_organization_id',
    'field' => 'sourceid',
  );
  $tables['feeds_data_gl_individuals']['table']['join']['migrate_map_individuals'] = array(
    'field' => 'person_ref',
    'left_field' => 'sourceid',
  );
  $tables['feeds_data_gl_relationships']['table']['join']['migrate_map_relationship'] = array(
    'field' => 'person_organization_id',
    'left_field' => 'sourceid',
  );

  return $tables;
}
