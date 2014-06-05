<?php

/**
 * @file
 * The default format for adresses.
 */

$plugin = array(
  'title' => t('Add an additional Address field'),
  'format callback' => 'addressfield_format_extension_address_generate',
  'type' => 'addressfield-extension-phone',
  'weight' => -99,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function addressfield_format_extension_address_generate(&$format, $address, $context = array()) {
  if ($context['mode'] == 'form') {
    $format['street_block']['address_3'] = array(
      '#title' => t('Address 3'),
      '#size' => 30,
      '#attributes' => array('class' => array('phone-number')),
      '#type' => 'textfield',
      '#tag' => 'div',
      '#default_value' => isset($address['address_3']) ? $address['address_3'] : '',
      '#weight' => 50,
    );
  }
  else {
    // Add our own render callback for the format view
    $format['#pre_render'][] = '_addressfield_format_extension_address_generate';
  }
}