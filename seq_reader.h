/*
 seq_reader.c
 project: seq_reader
 author: Isaac Turner <turner.isaac@gmail.com>
 Copyright (C) 20-June-2012
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SEQ_HEADER_SEEN
#define SEQ_HEADER_SEEN

#include "string_buffer.h"

typedef struct SequenceFile SequenceFile;
typedef struct SequenceKmerReader SequenceKmerReader;
typedef enum SequenceFileType SequenceFileType;

typedef struct
{
  STRING_BUFFER *name, *seq, *qual;
  int start, length;
} Sequence;

enum SequenceFileType
{
  SEQ_UNKNOWN = 0, SEQ_FASTA = 1, SEQ_FASTQ = 2, SEQ_PLAIN = 3,
  SEQ_SAM = 4, SEQ_BAM = 5,
};

char* seq_file_types[6];

// For creating/destroying struct for result
Sequence* seq_init();
void seq_destroy(Sequence* sequence);

SequenceFile* seq_file_open(const char* path);
void seq_file_close(SequenceFile* file);

void seq_file_force_type(SequenceFile* file, SequenceFileType);
SequenceFileType seq_file_get_type(const SequenceFile* file);

// Get a pointer to the file path (please don't modify it!)
const char* seq_file_get_path(const SequenceFile* file);

// Returns 0 if at end of file; 1 otherwise
char seq_file_read(SequenceFile* file, Sequence* sequence);

// Kmer reader
SequenceKmerReader* seq_file_get_kmer_reader(SequenceFile* file, int kmer_size);

// Returns 0 if at end of file; 1 otherwise
char seq_file_read_kmer(SequenceKmerReader* reader, Sequence* sequence);

#endif
