<?php

function extender_example_views_plugins() { 

  $path = drupal_get_path('module', 'saini');

  $plugins = array(); 

  $plugins['display_extender']['extender_example'] = array( 

    'title' => t('Extender example textarea'), 

    'help' => t('Add textarea.'), 

    'path' => $path, 

    'handler' => 'saini_plugin_display_extender_code',

  ); 
p($plugins);
  return $plugins; 

}