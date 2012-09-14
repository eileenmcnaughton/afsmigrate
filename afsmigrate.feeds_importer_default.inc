<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function afsmigrate_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gl_individuals';
  $feeds_importer->config = array(
    'name' => 'gl_individuals',
    'description' => 'People in GL',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => 1,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsDataProcessor',
      'config' => array(
        'update_existing' => 1,
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'PERSON_REF',
            'target' => 'person_ref',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'ENGLISH_FIRSTNAME',
            'target' => 'english_firstname',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'ENGLISH_LASTNAME',
            'target' => 'english_lastname',
            'unique' => 0,
          ),
          3 => array(
            'source' => 'MAILING_ADDRESS',
            'target' => 'mailing_address',
            'unique' => 0,
          ),
          4 => array(
            'source' => 'ENGLISH_NICKNAME',
            'target' => 'english_nickname',
            'unique' => 0,
          ),
          5 => array(
            'source' => 'PREFERRED_EMAIL',
            'target' => 'preferred_email',
            'unique' => 0,
          ),
          6 => array(
            'source' => 'PREFERRED_EMAIL2',
            'target' => 'preferred_email2',
            'unique' => 0,
          ),
          7 => array(
            'source' => 'SEX',
            'target' => 'sex',
            'unique' => 0,
          ),
          8 => array(
            'source' => 'ORGANIZATION_REF',
            'target' => 'organization_ref',
            'unique' => 0,
          ),
          9 => array(
            'source' => 'ORG_LINK_FROM_DATE',
            'target' => 'org_link_from_date',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'ORG_LINK_TO_DATE',
            'target' => 'org_link_to_date',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'STATUS',
            'target' => 'status',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'TITLE',
            'target' => 'title',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'WORK_EMAIL',
            'target' => 'work_email',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'WORK_FAX',
            'target' => 'work_fax',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'WORK_TELEPHONE',
            'target' => 'work_telephone',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'INSTANT_MESSAGE_ADDRESS',
            'target' => 'instant_message_address',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'COUNTRY',
            'target' => 'country',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'ENGLISH_ADDRESS1',
            'target' => 'english_address1',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'ENGLISH_ADDRESS2',
            'target' => 'english_address2',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'ENGLISH_CITY',
            'target' => 'english_city',
            'unique' => FALSE,
          ),
        ),
        'delete_with_source' => FALSE,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '86400',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );
  $export['gl_individuals'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gl_orgs';
  $feeds_importer->config = array(
    'name' => 'gl_orgs',
    'description' => 'GL Organisations',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => 1,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsDataProcessor',
      'config' => array(
        'update_existing' => 1,
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'ORG_TYPE',
            'target' => 'org_type',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'ORGANIZATION_ID_FOR_PL19',
            'target' => 'organization_id_for_pl19',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'MAIN_ORG_NAME',
            'target' => 'main_org_name',
            'unique' => 0,
          ),
          3 => array(
            'source' => 'ORGANIZATION_REF',
            'target' => 'organization_ref',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'MAIN_ORG_CHAPTER',
            'target' => 'main_org_chapter',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'MAIN_ORG_CHAPTER_ID',
            'target' => 'main_org_chapter_id',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'MAIN_ORG_CONTACT_NAME',
            'target' => 'main_org_contact_name',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'MAIN_ORG_COUNTRY',
            'target' => 'main_org_country',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'MAIN_ORG_ENGLISH_ADDRESS1',
            'target' => 'main_org_english_address1',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'MAIN_ORG_ENGLISH_ADDRESS2',
            'target' => 'main_org_english_address2',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'MAIN_ORG_ENGLISH_CITY',
            'target' => 'main_org_english_city',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'MAIN_ORG_ENGLISH_ZIP',
            'target' => 'main_org_english_zip',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'MAIN_ORG_ENGLISH_STATE',
            'target' => 'main_org_english_state',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'MAIN_ORG_WEB_SITE',
            'target' => 'main_org_web_site',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'ORG_STATUS',
            'target' => 'org_status',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'MAIN_ORG_EMAIL',
            'target' => 'main_org_email',
            'unique' => FALSE,
          ),
        ),
        'delete_with_source' => FALSE,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
  );
  $export['gl_orgs'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gl_relationships';
  $feeds_importer->config = array(
    'name' => 'gl_relationships',
    'description' => 'Relationships',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => 1,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsDataProcessor',
      'config' => array(
        'update_existing' => 1,
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'PERSON_ORGANIZATION_ID',
            'target' => 'person_organization_id',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'ORG_LINK_FROM_DATE',
            'target' => 'org_link_from_date',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'ORG_LINK_TO_DATE',
            'target' => 'org_link_to_date',
            'unique' => 0,
          ),
          3 => array(
            'source' => 'STATUS',
            'target' => 'status',
            'unique' => 0,
          ),
          4 => array(
            'source' => 'PERSON_REF',
            'target' => 'person_ref',
            'unique' => 0,
          ),
          5 => array(
            'source' => 'ORGANIZATION_REF',
            'target' => 'organization_ref',
            'unique' => 0,
          ),
          6 => array(
            'source' => 'CONNECTION_TYPE',
            'target' => 'connection_type',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'AFFILIATION_ID',
            'target' => 'affiliation_id',
            'unique' => FALSE,
          ),
        ),
        'delete_with_source' => FALSE,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
  );
  $export['gl_relationships'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gl_reltypes';
  $feeds_importer->config = array(
    'name' => 'gl_reltypes',
    'description' => 'GL Relationship Types',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => 1,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsDataProcessor',
      'config' => array(
        'update_existing' => 0,
        'expire' => -1,
        'mappings' => array(
          0 => array(
            'source' => 'AFFILIATION_ID',
            'target' => 'affiliation_id',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'AFFILIATION_TYPE',
            'target' => 'affiliation_type',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'CONNECTION_TYPE',
            'target' => 'connection_type',
            'unique' => 0,
          ),
        ),
        'delete_with_source' => FALSE,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
  );
  $export['afsmigrate'] = $feeds_importer;

  return $export;
}
