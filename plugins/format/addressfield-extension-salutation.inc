<?php

/**
 * @file
 * The default format for adresses.
 */
$plugin = array(
  'title' => t('Add Salutation Field'),
  'format callback' => 'addressfield_format_extension_salutation_generate',
  'type' => 'addressfield-extension-salutation.inc',
  'weight' => 99,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function addressfield_format_extension_salutation_generate(&$format, $address) {
  $format['name_block']['salutation'] = array(
    '#title' => t('Salutation'),
    '#attributes' => array('class' => array('salutation')),
    '#type' => 'select',
    '#required' => TRUE,
    '#multiple' => FALSE,
    '#options' => array(
	  	'Mr' => t('Mr'),
	  	'Mrs' => t('Mrs'),
	  	'Ms' => t('Ms'),
			'Dr' => t('Dr'),
			'HH' => t('HH'),
			'Lord' => t('Lord'),
			'Earl' => t('Earl'),
			'Baron' => t('Baron'),
			'Sir' => t('Sir'),
	  ),
	  '#weight' => -1,
  );
}
