/*
 * Copyright 2024 Tedd OKANO
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include	"r01lib.h"
r01lib_start;	/* *** place this word before making instance of r01lib classes *** */

I2C		i2c;

int main(void)
{
	PRINTF( "I2C output is available on D18/SDA and D19/SCL.\r\n" );
	PRINTF( "Pull-up resisters are required to connect I2C target(s)\r\n" );

	constexpr uint8_t	address		= 0x4C;
	uint8_t				w_data[]	= { 0 };
	uint8_t				r_data[ 2 ];

	while ( true )
	{
		i2c.write( address, w_data, sizeof( w_data ), NO_STOP );
		i2c.read(  address, r_data, sizeof( r_data ) );

		PRINTF( "0x %02X %02X\r\n", r_data[ 0 ], r_data[ 1 ] );
		wait( 1 );
	}
}