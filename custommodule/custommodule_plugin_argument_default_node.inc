<?php
 
 class custommodule_plugin_argument_default_node extends views_plugin_argument_default {

  /**
   * Get the default argument.
   */
  function get_argument() {
    $nids = array(1,2,3,100,125,124);
    return implode(',', $nids);
  }
}
