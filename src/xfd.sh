#!/bin/bash
# 

RETVAL=0
SERVER_ADDRESS_RESOLUTION=
XFD_PID_FILE="/var/log/xfd.pid"

# Check that networking is up.
. /etc/sysconfig/network

usage ()
{
	echo $"Usage: $0 {start|stop|restart|reload}" 1>&2
	RETVAL=2
}
	
start ()
{
	[ -f /usr/local/bin/xfd ] || exit 6
	/usr/local/bin/xfd
	/bin/ps -C xfd -o pid= > "$XFD_PID_FILE"
}

stop ()
{
    kill `cat "$XFD_PID_FILE"
}

restart ()
{
	stop
	start
}


case "$1" in
    stop) stop ;;
    status) status ;;
    start|restart|reload) restart ;;
    *) usage ;;
esac

exit $RETVAL
