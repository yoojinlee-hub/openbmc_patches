#!/bin/bash

# Step 1: Set TEMPLATECONF
export TEMPLATECONF=./meta-aspeed/conf/

# Step 2: Source openbmc-env build
source openbmc-env build

# Step 3: BitBake Application
read -p "Enter the Application name: " app_name
bitbake $app_name

