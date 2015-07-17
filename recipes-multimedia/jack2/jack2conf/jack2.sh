#!/bin/sh
#
### BEGIN INIT INFO
# Provides: jack2
# Required-Start: $local_fs $remote_fs
# Required-Stop: $local_fs $remote_fs
# Default-Start:     1 2 3 4 5
# Default-Stop:      0 6
### END INIT INFO

killproc() {            # kill the named process(es)
        pid=`/bin/pidof $1`
        [ "$pid" != "" ] && kill $pid
}

case "$1" in
  start)
       username=root
       echo "Starting jackd"
       su -l -c '/usr/bin/jackd -d alsa --device hw:1 &' $username 
  ;;

  stop)
        echo "Stopping XServer"
        killproc jackd
  ;;

  restart)
	$0 stop
        sleep 1
        $0 start
  ;;

  *)
        echo "usage: $0 { start | stop | restart }"
  ;;
esac

exit 0
