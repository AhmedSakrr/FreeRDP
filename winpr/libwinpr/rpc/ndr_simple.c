/**
 * WinPR: Windows Portable Runtime
 * Microsoft Remote Procedure Call (MSRPC)
 *
 * Copyright 2012 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>

#include <winpr/rpc.h>

#ifndef _WIN32

#include "ndr_simple.h"
#include "ndr_private.h"

const unsigned char SimpleTypeAlignment[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x07, 0x07, 0x01, 0x03, 0x03,
	0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x08, 0x08, 0x02, 0x04, 0x04,
	0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const unsigned char SimpleTypeBufferSize[] = {
	0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x08, 0x08, 0x02, 0x04, 0x04,
	0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x08, 0x08, 0x04, 0x04, 0x04,
	0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const unsigned char SimpleTypeMemorySize[] = {
	0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x08, 0x08, 0x04, 0x04, 0x04,
	0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,
	0x92, 0x9D, 0x3A, 0x75, 0x92, 0x9D, 0x3A, 0x75, 0x92, 0x9D, 0x3A, 0x75, 0x92, 0x9D, 0x3A, 0x75,
	0x92, 0x9D, 0x3A, 0x75, 0x92, 0x9D, 0x3A, 0x75, 0x92, 0x9D, 0x3A, 0x75, 0x92, 0x9D, 0x3A, 0x75,
	0x92, 0x9D, 0x3A, 0x75, 0x92, 0x9D, 0x3A, 0x75, 0x92, 0x9D, 0x3A, 0x75, 0x92, 0x9D, 0x3A, 0x75,
	0x92, 0x9D, 0x3A, 0x75, 0x92, 0x9D, 0x3A, 0x75, 0x92, 0x9D, 0x3A, 0x75, 0x92, 0x9D, 0x3A, 0x75,
};

const unsigned char NdrTypeFlags[] = {
	0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x02, 0x02, 0x02, 0x02, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x08, 0x08, 0x08, 0x08, 0x08,
	0x08, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xA0, 0xA0, 0x00, 0xC0, 0xC0, 0x02,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x84, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x04, 0x00, 0x01,
	0x03, 0x10, 0x01, 0x03, 0x2C, 0x01, 0x03, 0xE0, 0x90, 0x90, 0x8B, 0x57, 0x83, 0xE7, 0x6C, 0x01,
	0x09, 0x70, 0x3B, 0x86, 0x00, 0x0F, 0x01, 0x5A, 0x00, 0x80, 0x00, 0x30, 0x8D, 0x30, 0x84, 0x00,
	0x48, 0x6A, 0x00, 0x6A, 0x01, 0x06, 0xFF, 0x08, 0x5D, 0x90, 0x7D, 0x7D, 0x0F, 0x67, 0xBD, 0xAD,
	0xAD, 0xAD, 0x9B, 0xBA, 0x9B, 0x9B, 0x0D, 0xB9, 0xAD, 0x19, 0x19, 0xBA, 0xDB, 0x09, 0x86, 0xB1,
};

unsigned char NdrGetSimpleTypeBufferAlignment(unsigned char FormatChar)
{
	return SimpleTypeAlignment[FormatChar];
}

unsigned char NdrGetSimpleTypeBufferSize(unsigned char FormatChar)
{
	return SimpleTypeAlignment[FormatChar];
}

unsigned char NdrGetSimpleTypeMemorySize(unsigned char FormatChar)
{
	return SimpleTypeMemorySize[FormatChar];
}

int NdrGetTypeFlags(unsigned char FormatChar)
{
	return NdrTypeFlags[FormatChar];
}

void NdrSimpleTypeBufferSize(PMIDL_STUB_MESSAGE pStubMsg, unsigned char* pMemory,
                             PFORMAT_STRING pFormat)
{
	switch (*pFormat)
	{
		case FC_BYTE:
		case FC_CHAR:
		case FC_SMALL:
		case FC_USMALL:
			NdrpIncrementLength(&(pStubMsg->BufferLength), sizeof(BYTE));
			break;

		case FC_WCHAR:
		case FC_SHORT:
		case FC_USHORT:
		case FC_ENUM16:
			NdrpAlignLength(&(pStubMsg->BufferLength), sizeof(USHORT));
			NdrpIncrementLength(&(pStubMsg->BufferLength), sizeof(USHORT));
			break;

		case FC_LONG:
		case FC_ULONG:
		case FC_ENUM32:
		case FC_INT3264:
		case FC_UINT3264:
			NdrpAlignLength(&(pStubMsg->BufferLength), sizeof(ULONG));
			NdrpIncrementLength(&(pStubMsg->BufferLength), sizeof(ULONG));
			break;

		case FC_FLOAT:
			NdrpAlignLength(&(pStubMsg->BufferLength), sizeof(FLOAT));
			NdrpIncrementLength(&(pStubMsg->BufferLength), sizeof(FLOAT));
			break;

		case FC_DOUBLE:
			NdrpAlignLength(&(pStubMsg->BufferLength), sizeof(DOUBLE));
			NdrpIncrementLength(&(pStubMsg->BufferLength), sizeof(DOUBLE));
			break;

		case FC_HYPER:
			NdrpAlignLength(&(pStubMsg->BufferLength), sizeof(ULONGLONG));
			NdrpIncrementLength(&(pStubMsg->BufferLength), sizeof(ULONGLONG));
			break;

		case FC_ERROR_STATUS_T:
			NdrpAlignLength(&(pStubMsg->BufferLength), sizeof(error_status_t));
			NdrpIncrementLength(&(pStubMsg->BufferLength), sizeof(error_status_t));
			break;

		case FC_IGNORE:
			break;
	}
}

void NdrSimpleTypeMarshall(PMIDL_STUB_MESSAGE pStubMsg, unsigned char* pMemory,
                           unsigned char FormatChar)
{
}

void NdrSimpleTypeUnmarshall(PMIDL_STUB_MESSAGE pStubMsg, unsigned char* pMemory,
                             unsigned char FormatChar)
{
}

void NdrSimpleTypeFree(PMIDL_STUB_MESSAGE pStubMsg, unsigned char* pMemory, PFORMAT_STRING pFormat)
{
}

#endif
