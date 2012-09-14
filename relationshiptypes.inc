<?php

class RelationshipTypes extends Individual {
  protected $entity = 'relationship_type'; // this is the default
  protected $debug = 0;
  protected $keyField = 'affiliation_id';
  protected $description = "Relationship Types";
  public function __construct() {
    parent::__construct(1);
  }
  function prepare(&$entity,&$row){
  }

  function prepareRow($current_row){
    if ( $current_row->CONNECTION_TYPE == 'N/A'){
      return false;
    }
    return true;
  }
}
/*
 *  [person_ref] => 04-01500
    [ENGLISH_FIRSTNAME] => Ann
    [ENGLISH_LASTNAME] => Heffernan
    [ENGLISH_NICKNAME] =>
    [DATE_OF_BIRTH] => 2/22/1966 12:00:00 AM
    [mailing_address] => Family Address
    [ENGLISH_ZIP] => 9501
    [preferred_email] => annmh@clear.net.nz
    [preferred_email_two] =>
    [SEX] => F
    [TITLE] => Mrs.
    [work_email] =>
    [WORK_FAX] =>
    [WORK_TELEPHONE] => 03 217 3335
    [INSTANT_MESSAGE_ADDRESS] =>
    [COUNTRY] => New Zealand
    [ENGLISH_ADDRESS1] => 221 George Street
    [ENGLISH_ADDRESS2] =>
    [ENGLISH_CITY] => Invercargill
    [PERSON_ID] => 4ef34e18-b962-4439-99b3-48a33ccb6671
    [NATIVE_TITLE] => Mrs.
    [NATIVE_FIRSTNAME] => Ann
    [NATIVE_LASTNAME] => Heffernan
    [NATIVE_NICKNAME] =>
    [NATIVE_ADDRESS1] => 221 George Street
    [NATIVE_ADDRESS2] =>
    [NATIVE_CITY] => Invercargill
    [NATIVE_ZIP] => 9501
    [MAIN_ORG_ID] => 3fc20b2d-3de7-4792-a649-fdddde310578
    [ORG_LINK_FROM_DATE] => 4/29/2002 12:00:00 AM
    [ORG_LINK_TO_DATE] => 4/29/2002 12:00:00 AM
    [STATUS] => Inactive
    [PERSON_ROLE] => Active
    [affiliation_id] => 034d155b-79e7-4d1b-ab13-cdf7a86d074d
    [AFFILIATION_TYPE] =>
    [CONNECTION_TYPE] => N/A
    [GL_AFFILIATION] =>
    [organization_ref] => 04-00022
    [ORG_TYPE] => AFS Chapter
    [ORGANIZATION_ID_FOR_PL19,ORGANIZATION_ID_FOR_PL19] => 3fc20b2d-3de7-4792-a649-fdddde310578
    [MAIN_ORG_NAME] => Southland
    [MAIN_ORG_NATIVE_NAME] => Southland
    [MAIN_ORG_CHAPTER] =>
    [MAIN_ORG_CHAPTER_ID] =>
    [MAIN_ORG_CONTACT_NAME] =>
    [MAIN_ORG_COUNTRY] => New Zealand
    [main_org_english_address1] =>
    [MAIN_ORG_ENGLISH_ADDRESS2] =>
    [MAIN_ORG_ENGLISH_CITY] =>
    [MAIN_ORG_ENGLISH_ZIP] =>
    [MAIN_ORG_ENGLISH_STATE] =>
    [MAIN_ORG_NATIVE_ADDRESS1] =>
    [MAIN_ORG_NATIVE_ADDRESS2] =>
    [MAIN_ORG_NATIVE_CITY] =>
    [MAIN_ORG_NATIVE_STATE] =>
    [MAIN_ORG_NATIVE_ZIP] =>
    [main_org_email] =>
    [MAIN_ORG_FAXNUM] =>
    [NATIVE_ORG_SUB_TYPE] =>
    [MAIN_ORG_WEB_SITE] =>
    [ORG_STATUS] => Active
    [person_organization_id] => 14d3467b-01c9-44dd-9e7a-b1f367c7181b
    [migrate_map_sourceid1] => 034D155B-79E7-4D1B-AB13-CDF7A86D074D
    [migrate_map_destid1] => 56
    [migrate_map_needs_update] => 1
    [migrate_map_last_imported] => 0
)

Params as passed to APIArray
(
    [name_a_b] => N/A
    [label_a_b] => N/A
    [name_b_a] => N/A
    [label_b_a] => N/A
    [description] => N/A
    [contact_type_a] => Individual
    [contact_type_b] => Organization
    [is_reserved] => 0
    [is_active] => 1
    [id] => 56
    [migrate] => Array
        (
            [machineName] => RelationshipTypes
        )

    [version] => 3
 */