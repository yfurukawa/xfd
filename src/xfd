#!/bin/bash
# 

RETVAL=0

usage ()
{
	echo $"Usage: $0 {start|stop|restart|reload}" 1>&2
	RETVAL=2
}
	
start ()
{
	[ -f /usr/local/bin/xfd ] || exit 6
	/usr/local/bin/xfd
}

restart ()
{
	start
}


case "$1" in
    stop) kill `ps -C xfd -o pid=` > /dev/null ;;
    status) status ;;
    start|restart|reload) restart ;;
    *) usage ;;
esac

exit $RETVAL
