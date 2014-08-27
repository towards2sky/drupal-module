<?php
/**
 * Implements hook_views_plugins().
 */
class saini_plugin_display_extender_code extends views_plugin_display_extender {

  /** 

   * Provide a form to edit options for this plugin. 

   */
  function option_definition(&$options) { 

   $options['extender_example'] = array('default' => '');

  } 

 

  /** 
16
   * Provide the form to set new option. 
17
   */

  function options_form(&$form, &$form_state) { 

    switch ($form_state['section']) { 
      case 'extender_example': 
        $form['#title'] .= t('Example setting'); 
        $form['extender_example'] = array( 
          '#type' => 'textarea', 
          '#description' => t('Custom text which will display whenever you want'),
          '#default_value' => $this->display->get_option('extender_example'), 
        ); 
        break; 
    } 
  } 

    
  /** 
   * Inserts the code into the view display. 
   */
  function options_submit(&$form, &$form_state) { 
    $new_option  = $form_state['values']['extender_example']; 
    switch ($form_state['section']) { 
      case 'extender_example': 
        $this->display->set_option('extender_example', $new_option); 
        $empty = trim($new_option); 
        $empty = empty($empty); 
        break; 
    } 
  } 

 

  /** 
   * Summarizes new option. 
   * 
   * Lists the fields as either 'Yes' if there is text or 'None' otherwise and
   * categorizes the fields under the 'Other' category. 
   */

  function options_summary(&$categories, &$options) { 

    $new_option = check_plain(trim($this->display->get_option('extender_example'))); 
    if ($new_option) { 
      $new_option = t('Yes'); 
    } 
    else { 
      $new_option = t('None'); 
    } 
    $options['extender_example'] = array( 
      'category' => 'other', 
      'title'    => t('Extender example'), 
      'value'    => $new_option, 
      'desc'     => t('Add some option.'), 
    ); 

  } 

}