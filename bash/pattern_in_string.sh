#!/bin/bash

# Demos ["=~" operator](http://tldp.org/LDP/abs/html/bashver3.html#REGEXMATCHREF):
# if [[ "string_we_want_to_look_for_pattern" =~ "pattern" ]]; then
# ...

command1="cd1w2"
command2="cd Documents/projects"
command3="cd"

# cd in command1
if [[ "$command1" =~ "cd" ]]; then
    echo "cd in command1"
else
    echo "cd not in command1"
fi

# cd in command2
if [[ "$command2" =~ "cd" ]]; then
    echo "cd in command2"
else
    echo "cd not in command2"
fi

# cd in command3
if [[ "$command3" =~ "cd" ]]; then
    echo "cd in command3"
else
    echo "cd not in command3"
fi
