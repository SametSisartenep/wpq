</$objtype/mkfile

BIN=$home/bin/$objtype
TARG=wpqprompt
OFILES=\
	wpqprompt.$O

RCBIN=$home/bin/rc
RCSCR=\
	wpq

</sys/src/cmd/mkone

install:V:	$BIN/$TARG
	cp $RCSCR $RCBIN

uninstall:V:
	rm -f $BIN/$TARG $RCBIN/$RCSCR
