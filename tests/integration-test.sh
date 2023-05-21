#!/bin/bash

./server &

sleep 5

./integration_tests

killall server
