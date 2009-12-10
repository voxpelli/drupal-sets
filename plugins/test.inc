<?php
// $Id$

/**
 * Implementation of hook_set_provider().
 */
function sets_test_set_provider() {
  return array(
    'sets list' => 'sets_test_sets_list',
    'set load'  => 'sets_test_set_load',
  );
}

function sets_test_sets_list() {
  return array(
    'test',
    'test2',
    'kalle',
  );
}

function sets_test_set_load($set, $context = NULL) {
  switch ($set) {
    case 'test':
      $return = array(
        'foobar1',
        'foobar2',
        'foobar3',
        'foobar4',
      );
      break;
    case 'test2':
      $return = array(
        'foo1',
        'foo2',
        'foo3',
        'foo4',
      );
      break;
    case 'kalle':
      $return = array(
        'kalle1',
        'kalle2',
        'kalle3',
        'kalle4',
      );
      break;
    default:
      $return = array();
      break;
  }
  return $return;
}