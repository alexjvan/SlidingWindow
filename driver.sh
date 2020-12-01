# SIP=
# CIP=
EXE=HW3
SOURCE=kez_udphw3.cpp
NAME="---------------Sliding Window Assignment---------------"

# If the previous files weren't cleaned, remove it
if test -f "$EXE"; then
  rm $EXE
fi

# Compile
g++ $SOURCE -o $EXE 

# Run with arg(s)

if test -f "$EXE"; then
  echo $NAME
  echo "Starting test1..."
  ./$EXE localhost
fi


# Clean up
if test -f "$EXE"; then
  rm $EXE
fi