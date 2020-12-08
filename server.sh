# CSS432VM_04
# SERVERIP=127.0.0.1
# CIP=
EXE=HW3
SOURCE=kez_udphw3.cpp
DEST=data
NAME="---------------Sliding Window Assignment---------------"

# If the previous files weren't cleaned, remove it
if test -f "$EXE"; then
  rm $EXE
fi

# Compile
g++ UdpSocket.cpp Timer.cpp kez_udphw3.cpp hw3.cpp -o $EXE

# Run with arg(s)

if test -f "$EXE"; then
  echo $NAME
  echo "Starting test1......"
  echo "Starting server......"
  ./$EXE 
  echo "......End server."
  echo "......End test1."
fi


# Clean up
# if test -f "$EXE"; then
#   rm $EXE
# fi