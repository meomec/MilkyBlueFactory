<?php
/**
 * @file
 * Metatag integration for the metatag_path module.
 */

/**
 * Implements hook_metatag_config_instance_info().
 */
function metatag_path_metatag_config_instance_info() {
  $info['metatag_path'] = array('label' => t('Metatag path'));
  $instances = _metatag_path_load_all_instances();
  foreach ($instances as $instance) {
    $info['metatag_path:' . $instance->machine_name] = array('label' => $instance->title);
  }
  return $info;
}

/**
 * Implements hook_metatag_config_default().
 */
function metatag_path_metatag_config_default() {
  $configs = array();

  $config = new stdClass();
  $config->instance = 'metatag_path';
  $config->api_version = 1;
  $config->disabled = FALSE;
  $config->config = array(
    'title' => array('value' => '[current-page:title] | [current-page:pager][site:name]'),
    'canonical' => array('value' => '[current-page:url:absolute]'),
    'shortlink' => array('value' => '[current-page:url:unaliased]'),
  );
  $configs[$config->instance] = $config;

  return $configs;
}
