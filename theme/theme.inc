<?php
/**
 * @file
 * Theming and preprocess functions.
 */

/**
 * Implements hook_preprocess().
 */
function ah_dhcommons_preprocess_dhcommons_dirt(array &$variables) {
  $path = drupal_get_path('module', 'ah_dhcommons');
  drupal_add_css("$path/css/dhcommons_dirt.css");
  $label = t("@tool on DiRT", array('@tool' => $variables['title']));
  $node_url = variable_get('ah_dhcommons_dirt_url', ''). "/{$variables['path']}";
  $variables['link'] = l($label, $node_url);
}
