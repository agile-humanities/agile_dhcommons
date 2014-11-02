<?php
/**
 * @file
 * admin form
 */

/**
 * Admin form.
 *
 * @return array
 *   Returns admin form.
 */
function ah_dhcommons_admin() {
  $form = array();
  $form['ah_dhcommons_dirt_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('API Key'),
    '#default_value' => variable_get('ah_dirt_api_key', ''),
    '#description' => t('API Key to access DiRT'),
  );
  $form['ah_dhcommons_dirt_url'] = array(
    '#type' => 'textfield',
    '#title' => t('DiRT url'),
    '#default_value' => variable_get('ah_dhcommons_dirt_url', 'http://test.bamboodirt.gotpantheon.com'),
    '#description' => t('Full address of DiRT site'),
  );
  $form['ah_dhcommons_dirt_rest_path'] = array(
    '#type' => 'textfield',
    '#title' => t('REST Path'),
    '#default_value' => variable_get('ah_dhcommons_dirt_rest_path', 'rest'),
    '#description' => t('rest path - as provided by DiRT administrator'),
  );
  $form['ah_dhcommons_dirt_alias'] = array(
    '#type' => 'textfield',
    '#title' => t('Alias'),
    '#default_value' => variable_get('ah_dhcommons_dirt_alias', 'tool'),
    '#description' => t('alias - as provided by DiRT administrator'),
  );
  $form['ah_dhcommons_max_tool_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum number of results to display'),
    '#default_value' => variable_get('ah_dhcommons_max_tool_count', '5'),
    '#description' => t('Max number of results to show per page.'),
    '#size' => 5,
  );

  return system_settings_form($form);
}
