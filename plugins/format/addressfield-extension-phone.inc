<?php

/**
 * @file
 * The default format for adresses.
 */

$plugin = array(
  'title' => t('Add Phone Number'),
  'format callback' => 'addressfield_format_extension_phone_generate',
  'type' => 'addressfield-extension-phone',
  'weight' => -99,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function addressfield_format_extension_phone_generate(&$format, $address, $context = array()) {
  if ($context['mode'] == 'form') {
  	$format['phone_block'] = array(
	    '#type' => 'addressfield_container',
	    '#attributes' => array(
	      'class' => array('addressfield-container-inline', 'phone-block'),
	    ),
	    '#weight' => 100,
	  );
    $format['phone_block']['phone_number'] = array(
      '#title' => t('Phone Number'),
      '#size' => 30,
      '#attributes' => array('class' => array('phone-number')),
      '#type' => 'textfield',
      '#tag' => 'span',
      '#default_value' => isset($address['phone_number']) ? $address['phone_number'] : '',
      '#weight' => 99,
    );
  }
  else {
    // Add our own render callback for the format view
    $format['#pre_render'][] = '_addressfield_format_extension_phone_generate';
  }
}