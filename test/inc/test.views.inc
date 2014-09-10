<?php
/**
* Implementation of hook_views_handlers() to register all of the basic handlers
* views uses.
*/
function test_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'test') . '/inc', // path to view files
    ),
    'handlers' => array(
      // register our custom filter, with the class/file name and parent class
      'test_filter_multiple' => array(
        'parent' => 'views_handler_filter',
      )
    ),
  );
}

function test_views_data() {
  $data = array();
  
  // The flexible date filter.
  $data['node']['test'] = array(
    'group' => t('Custom'),
    'real field'  => 'test',
    'title' => t('Custom Date/Term combined filter'),
    'help' => t('Filter any Views based on date and term'),
    'filter' => array(
      'handler' => 'test_filter_multiple'
    ),
  ); 
  
  return $data;
}