/*
 * The data block data stream handle functions
 *
 * Copyright (C) 2018, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBFSAPFS_DATA_BLOCK_DATA_STREAM_HANDLE_H )
#define _LIBFSAPFS_DATA_BLOCK_DATA_STREAM_HANDLE_H

#include <common.h>
#include <types.h>

#include "libfsapfs_io_handle.h"
#include "libfsapfs_libbfio.h"
#include "libfsapfs_libcerror.h"
#include "libfsapfs_libfcache.h"
#include "libfsapfs_libfdata.h"
#include "libfsapfs_volume_data_handle.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libfsapfs_data_block_data_stream_handle libfsapfs_data_block_data_stream_handle_t;

struct libfsapfs_data_block_data_stream_handle
{
	/* The current segment offset
	 */
	off64_t current_segment_offset;

	/* The IO handle
	 */
	libfsapfs_io_handle_t *io_handle;

	/* The data block vector
	 */
	libfdata_vector_t *data_block_vector;

	/* The data block cache
	 */
	libfcache_cache_t *data_block_cache;
};

int libfsapfs_data_block_data_stream_handle_initialize(
     libfsapfs_data_block_data_stream_handle_t **data_stream_handle,
     libfsapfs_io_handle_t *io_handle,
     libfsapfs_volume_data_handle_t *volume_data_handle,
     libcerror_error_t **error );

int libfsapfs_data_block_data_stream_handle_free(
     libfsapfs_data_block_data_stream_handle_t **data_stream_handle,
     libcerror_error_t **error );

ssize_t libfsapfs_data_block_data_stream_handle_read_segment_data(
         libfsapfs_data_block_data_stream_handle_t *data_stream_handle,
         libbfio_handle_t *file_io_handle,
         int segment_index,
         int segment_file_index,
         uint8_t *segment_data,
         size_t segment_data_size,
         uint32_t segment_flags,
         uint8_t read_flags,
         libcerror_error_t **error );

off64_t libfsapfs_data_block_data_stream_handle_seek_segment_offset(
         libfsapfs_data_block_data_stream_handle_t *data_stream_handle,
         intptr_t *file_io_handle,
         int segment_index,
         int segment_file_index,
         off64_t segment_offset,
         libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFSAPFS_DATA_BLOCK_DATA_STREAM_HANDLE_H ) */
