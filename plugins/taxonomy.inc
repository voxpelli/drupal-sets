<?php
// $Id$

/**
 * Implementation of hook_PLUGIN_set_provider().
 */
function sets_taxonomy_set_provider() {
  return array(
    'sets list' => 'sets_taxonomy_sets_list',
    'set load'  => 'sets_taxonomy_set_load',
  );
}

function sets_taxonomy_sets_list() {
  $result = array();
  $vocabularies = taxonomy_get_vocabularies();
  foreach ($vocabularies as $vocabulary) {
    $name = 'taxonomy-' . sets_clean_tag($vocabulary->name);
    $result[$name] = array(
      'vid' => $vocabulary->vid,
      'description' => t('Set of taxonomy terms in the vocabulary @vocabulary', array('@vocabulary' => $vocabulary->name)),
    );
  }
  return $result;
}

function sets_taxonomy_set_load($set) {
  $result = array();
  $tree = taxonomy_get_tree($set['vid']);

  foreach ($tree as $term) {
    $result[] = $term->name;
  }

  return $result;
}