#!/bin/bash

# The following snippet shows how we can find the line number in bash when an error occured
#
# $ ./report_LOC_on_error.sh 
# cp: f1: No such file or directory
# Failed at 20: cp -- "$file1" "$file2"
#

# See: https://www.gnu.org/software/bash/manual/html_node/The-Set-Builtin.html
set -eET

file1=f1
file2=f2
file3=f3
file4=f4

failure() {
  local lineno=$1
  local msg=$2
  echo "Failed at $lineno: $msg"
}
trap 'failure ${LINENO} "$BASH_COMMAND"' ERR

cp -- "$file1" "$file2"
cp -- "$file3" "$file4"
