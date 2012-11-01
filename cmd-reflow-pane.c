/* $Id$ */

/*
 * Copyright (c) 2012 Richard Woodbury <rpwoodbu@mybox.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "tmux.h"

/*
 * Reflow text in a pane to suit its current size.
 */

enum cmd_retval	 cmd_reflow_pane_exec(struct cmd *, struct cmd_ctx *);

const struct cmd_entry cmd_reflow_pane_entry = {
	"reflow-pane", "reflow",
	"t:", 0, 0,
	CMD_TARGET_PANE_USAGE,
	0,
	NULL,
	NULL,
	cmd_reflow_pane_exec
};

enum cmd_retval
cmd_reflow_pane_exec(struct cmd *self, struct cmd_ctx *ctx)
{
	struct args		*args = self->args;
	struct window_pane	*wp;

	if (cmd_find_pane(ctx, args_get(args, 't'), NULL, &wp) == NULL)
		return (CMD_RETURN_ERROR);

	window_pane_reflow(wp);

	return (CMD_RETURN_NORMAL);
}
