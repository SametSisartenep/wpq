#include <u.h>
#include <libc.h>
#include <json.h>

void
usage(void)
{
	fprint(2, "usage: %s wpqsearchfile\n", argv0);
	exits("usage");
}

void
main(int argc, char *argv[])
{
	JSON *obj, *res;
	JSONEl *e;
	char buf[8192], *targets[32];
	int fd, n, i;

	JSONfmtinstall();
	ARGBEGIN{
	default: usage();
	}ARGEND;
	if(argc != 1)
		usage();
	fd = open(argv[0], OREAD);
	if((n = readn(fd, buf, sizeof(buf)-1)) <= 0)
		sysfatal("read: %r");
	buf[n] = 0;
	close(fd);
	obj = jsonparse(buf);
	if(obj == nil || obj->t != JSONObject)
		sysfatal("jsonparse: %r");
	res = jsonbyname(obj, "result");
	if(res == nil || res->t != JSONArray)
		sysfatal("jsonbyname: %r");
	if(res->first->next->val->first == nil)
		sysfatal("no results");
	for(e = res->first->next->val->first, i = 0; e != nil && i < nelem(targets); e = e->next, i++){
		targets[i] = e->val->s;
		fprint(2, "%d) %s\n", i+1, targets[i]);
	}
	if(i < 2)
		n = i;
	else{
prompt:
		fprint(2, "[1-%d]: ", i);
		if((n = read(0, buf, sizeof(buf)-1)) <= 0)
			sysfatal("read: %r");
		buf[n] = 0;
		n = strtol(buf, nil, 0);
		if(n < 1 || n > i)
			goto prompt;
	}
	print("%s\n", targets[n-1]);
	jsonfree(obj);
	exits(0);
}
