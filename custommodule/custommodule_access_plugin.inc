<?php
 
  /**
   * Access plugin that provides property based access control.
   */
  class custommodules_access_plugin extends views_plugin_access {
 
    function summary_title() {
      return t('Custom acces plugin');
    } // summary_title()
 
  /**
   * Determine if the current user has access or not.
   */
    function access($account) {    
      return custommodules_access($account);
    }
 
    function get_access_callback() {
      return array('custommodules_access', array());
    }
 
  }