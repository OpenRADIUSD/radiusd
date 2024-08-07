/*	$OpenBSD: control.h,v 1.1 2024/07/09 17:26:14 yasuoka Exp $ */

/*
 * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _CONTROL_H_
#define	_CONTROL_H_

#include <sys/queue.h>
#include <sys/time.h>
#include <event.h>
#include <imsg.h>

#include "radiusd_local.h"

struct ctl_conn {
	uint32_t		id;
	TAILQ_ENTRY(ctl_conn)	entry;
	struct imsgev		iev;
	char			modulename[RADIUSD_MODULE_NAME_LEN + 1];
};

int	control_check(char *);
int	control_init(const char *);
int	control_listen(void);
void	control_accept(int, short, void *);
void	control_dispatch_imsg(int, short, void *);
int	control_imsg_relay(struct imsg *);
void	control_cleanup(void);
void	control_conn_bind(uint32_t, const char *);

#endif	/* _CONTROL_H_ */
