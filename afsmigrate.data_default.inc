<?php

/**
 * Implementation of hook_data_default().
 */
function afsmigrate_data_default() {
  $export = array();

  $data_table = new stdClass;
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'gl_individuals';
  $data_table->name = 'feeds_data_gl_individuals';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'feed_nid' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => '',
      ),
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => '',
      ),
      'timestamp' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => FALSE,
        'description' => '',
      ),
      'person_ref' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'english_firstname' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'english_lastname' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'mailing_address' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'english_nickname' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'preferred_email' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'preferred_email2' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'sex' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'organization_ref' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'org_link_from_date' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'org_link_to_date' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'status' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'title' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'work_email' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'work_fax' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'work_telephone' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'instant_message_address' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'country' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'english_address1' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'english_address2' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'english_city' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
    ),
    'name' => 'feeds_data_gl_individuals',
    'indexes' => array(
      'feed_nid' => array(
        0 => 'feed_nid',
      ),
      'id' => array(
        0 => 'id',
      ),
      'timestamp' => array(
        0 => 'timestamp',
      ),
    ),
    'primary key' => array(
      0 => 'id',
    ),
  );
  $data_table->meta = FALSE;
  $export['feeds_data_gl_individuals'] = $data_table;

  $data_table = new stdClass;
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'gl_orgs';
  $data_table->name = 'feeds_data_gl_orgs';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'feed_nid' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => '',
      ),
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => '',
      ),
      'timestamp' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => FALSE,
        'description' => '',
      ),
      'org_ref' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'org_type' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'organization_id_for_pl19' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'main_org_name' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'organization_ref' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'main_org_chapter' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'main_org_chapter_id' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'main_org_contact_name' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'main_org_country' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'main_org_english_address1' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'main_org_english_address2' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'main_org_english_city' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'main_org_english_zip' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'main_org_english_state' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'main_org_web_site' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'org_status' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'main_org_email' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'main_org_faxnum' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
    ),
    'name' => 'feeds_data_gl_orgs',
    'indexes' => array(
      'feed_nid' => array(
        0 => 'feed_nid',
      ),
      'id' => array(
        0 => 'id',
      ),
      'timestamp' => array(
        0 => 'timestamp',
      ),
    ),
    'primary key' => array(
      0 => 'id',
    ),
  );
  $data_table->meta = FALSE;
  $export['feeds_data_gl_orgs'] = $data_table;

  $data_table = new stdClass;
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'gl_relationships';
  $data_table->name = 'feeds_data_gl_relationships';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'feed_nid' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => '',
      ),
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => '',
      ),
      'timestamp' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => FALSE,
        'description' => '',
      ),
      'person_organization_id' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'org_link_from_date' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'org_link_to_date' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'status' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'person_ref' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'organization_ref' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'connection_type' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'affiliation_id' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
    ),
    'name' => 'feeds_data_gl_relationships',
    'indexes' => array(
      'feed_nid' => array(
        0 => 'feed_nid',
      ),
      'id' => array(
        0 => 'id',
      ),
      'timestamp' => array(
        0 => 'timestamp',
      ),
    ),
    'primary key' => array(
      0 => 'id',
    ),
  );
  $data_table->meta = FALSE;
  $export['feeds_data_gl_relationships'] = $data_table;

  $data_table = new stdClass;
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'gl_reltypes';
  $data_table->name = 'feeds_data_gl_reltypes';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'feed_nid' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => '',
      ),
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => '',
      ),
      'timestamp' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => FALSE,
        'description' => '',
      ),
      'affiliation_id' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'affiliation_type' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'connection_type' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
    ),
    'name' => 'feeds_data_gl_reltypes',
    'indexes' => array(
      'feed_nid' => array(
        0 => 'feed_nid',
      ),
      'id' => array(
        0 => 'id',
      ),
      'timestamp' => array(
        0 => 'timestamp',
      ),
    ),
    'primary key' => array(
      0 => 'id',
    ),
  );
  $data_table->meta = FALSE;
  $export['feeds_data_gl_reltypes'] = $data_table;

  return $export;
}
