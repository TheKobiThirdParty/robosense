Robosense Package
===================

This gives the ability to use the Robosense Lidars from the bare API (no ROS or other middleware)

It uses: boost and pcap, thus you should install pcap with:

```bash
sudo apt-get install -y  libpcap-dev
git clone git@github.com:TheKobiCompany/kobi_robosense.git --recursive
```

The rs_driver backend library (in submodule) is also installed and avaiable under the original `rs_driver` name (to avoid conflicts).
