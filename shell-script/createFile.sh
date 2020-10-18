#!/bin/bash

codeforces() {
    usage="Arguments should be like
    contestName LastQuestionChar"
    if [ -z "$1" ]; then
        display_help "$usage"
        exit 1
    fi
    dir_path="$CP_PATH"/codeforces/"$1"
    mkdir -p "$dir_path"
    LastQuestionChar="E"
    
    if [ "$2" ]; then
        LastQuestionChar="$2"
    fi
    LastQuestionChar=${LastQuestionChar^^}
    cd "$dir_path"
    
    rang=/{A.."${LastQuestionChar:0:1}"}.cpp < "../CP/template.cpp"
    echo "$rang"
    # tee 
    # geany "$dir_path"/{A.."${LastQuestionChar:0:1}"}.cpp &
}

codechef() {
    echo 'codechef'
}

atcoder() {
    echo 'atcoder'
}

leetcode() {
    echo 'leetcode'
}

display_help() {
    echo "$1" >&2
    exit 1
}

check_env() {
    if [ -z "$CP_PATH" ]; then
        echo "CP_PATH is not define in environment variable"
        echo "How to set path in environment? Put this in your .***rc file"
        echo
        echo "CP_PATH=$HOME/cp"
        echo "export CP_PATH"
        exit 1
    fi
}


# check_env() {
    # if [ -z "$CP_PATH" ]; then
        # echo "CP_PATH is not define in environment variable"
        # echo "https://stackoverflow.com/questions/234742/setting-environment-variables-in-linux-using-bash"
        # exit 1
    # if
# }

usage="Usage: "$0" [option...] [args...]
Where:
    [ -cf | --codeforces ]   crate file for codeforces contest
    [ -c  | --codechef   ]   crate file for codechef contest
    [ -a  | --atcoder    ]   crate file for atcoder contest
    [ -l  | --leetcode   ]   crate file for leetcode contest
    [ -k  | --kickstart  ]   crate file for kickstart contest
    [ -h  | --help       ]   show help
    "

check_env

case "$1" in
    -cf | --codeforces)
        shift 1
        codeforces $@
        ;;
    -c | --codechef)
        codechef # calling function stop()
        ;;
    -a | --atcoder)
        atcoder  # calling function stop()
        ;;
    -l | --leetcode)
        leetcode  # calling function stop()
        ;;
    -k | --kickstart)
        stop
        ;;
    -h | --help)
        display_help "$usage"
        ;;
    -*)
        echo "Error: Unknown option: $1" >&2
        ## or call function display_help
        exit 1 
        ;;
esac

exit 0
