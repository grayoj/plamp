#!/bin/bash

./server &

sleep 5

./load_test

killall server
