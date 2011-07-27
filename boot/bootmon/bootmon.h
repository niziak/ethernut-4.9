#ifndef _BOOTMON_H
#define _BOOTMON_H

/*
 * Copyright (C) 2005-2007 by egnite Software GmbH
 * Copyright (C) 2010 by egnite GmbH
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holders nor the names of
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * For additional information see http://www.ethernut.de/
 *
 */

/*
 * $Id: bootmon.h 2954 2010-04-03 11:22:40Z haraldkipp $
 */

#include "ether.h"
#include "arp.h"
#include "ip.h"
#include "udp.h"
#include "dhcp.h"
#include "tftp.h"
#include "config.h"
#include "utils.h"

typedef struct __attribute__ ((packed)) {
    IPHDR ip_hdr;
    UDPHDR udp_hdr;
    union {
        TFTPHDR tftp;
        BOOTPHDR bootp;
    } u;
} UDPFRAME;

typedef struct __attribute__ ((packed)) {
    ETHERHDR eth_hdr;
    union {
        ETHERARP arp;
        UDPFRAME udp;
    } eth;
} ETHERFRAME;

extern unsigned long random_id;

/*
 * Outgoing frame.
 */
extern ETHERFRAME sframe;

/*
 * Incoming frame.
 */
extern ETHERFRAME rframe;

#endif