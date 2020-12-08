SERVERIP=css432b-04
# CIP=
EXE=HW3
SOURCE=kez_udphw3.cpp
DEST=data
NAME="---------------Sliding Window Assignment---------------"

if test -f "$EXE"; then
  echo $NAME
  echo "Starting test1......"
  echo "Starting client......"
  ./$EXE $SERVERIP > $DEST 
  echo "......End client."
  echo "......End test1."
fi
