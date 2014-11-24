<?php
/**
 * @file
 * Utility REST functions.
 */

/**
 * Retrieves DiRT data through REST.
 *
 * @global url $base_url
 *
 * @param string $nitems
 *   number of items to return
 * @param array $tools
 *   Name of tools to be returned
 */
function ah_dhcommons_dirt_fetch($nitems = NULL, $tools = NULL) {
  $dirt_url = variable_get('ah_dhcommons_dirt_url', 'http://test.bamboodirt.gotpantheon.com');
  $rest_path = variable_get('ah_dhcommons_dirt_rest_path', 'rest');
  $alias = variable_get('ah_dhcommons_dirt_alias', 'tool');
  $url = "$dirt_url/$rest_path/$alias";
  $api_key = variable_get('ah_dhcommons_dirt_api_key', '');
  $post_data = array(
    'api-key' => $api_key,
    'nitems' => $nitems,
    'tools' => serialize($tools),
  );
  $data = http_build_query($post_data, '', '&');
  $options = array(
    'headers' => array('Accept' => 'application/json',
      'Content-Type' => 'application/x-www-form-urlencoded'),
    'method' => 'POST',
    'data' => $data
  );
  $response = drupal_http_request($url . '/fetch', $options);
  $objects = json_decode($response->data);
  $links = '';
  foreach ($objects as $object) {
    foreach ($object as $key => $value) {
      $converted_object[$key] = $value;
    }
    $links .= theme('dhcommons_dirt', $converted_object);
  }
  return $links;
}

/**
 * Parses urls to retrieve TID of term.
 *
 * @return string
 *   Tool Name
 */
function ah_dhcommons_dirt_get_term() {
  $path_parts = explode('/',$_GET['q']);
  if ($path_parts[1] == 'term' && isset($path_parts[2])) {
    $tid = $path_parts[2];
  }
  $term = taxonomy_term_load($tid);
  return ah_dhcommons_dirt_fetch(NULL, array($term->name));
}
