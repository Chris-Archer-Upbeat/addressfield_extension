<?php

/**
 * @file
 * The default format for adresses.
 */

$plugin = array(
  'title' => t('Add Mobile Number'),
  'format callback' => 'addressfield_format_extension_mobile_generate',
  'type' => 'addressfield-extension-mobile',
  'weight' => -99,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function addressfield_format_extension_mobile_generate(&$format, $address, $context = array()) {
  if ($context['mode'] == 'form') {
    $format['phone_block']['mobile_number'] = array(
      '#title' => t('Mobile Number'),
      '#size' => 30,
      '#attributes' => array('class' => array('mobile-number')),
      '#type' => 'textfield',
      '#tag' => 'span',
      '#default_value' => isset($address['mobile_number']) ? $address['mobile_number'] : '',
      '#weight' => 99,
    );
  }
  else {
    // Add our own render callback for the format view
    $format['#pre_render'][] = '_addressfield_format_extension_mobile_generate';
  }
}