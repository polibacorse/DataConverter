# DataConverter


### Dependencies on Fedora
To build the project you need to install required dependencies:
```
# dnf install make qt5 qt5-devel mosquitto mosquitto-devel
```

### Dependencies on Raspbian

```
# apt-get install qtbase5-dev qtbase5-dev-tools qt5-default libmosquitto-dev mosquitto
```

### Build
Follow this steps to generate Makefile and compile:
```
$ qmake-qt5 DataConverter.pro
$ make
```
