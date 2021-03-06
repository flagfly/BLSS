
/*
 * Copyright (C) 2017 Gnolizuh
 */


#ifndef _NGX_RTMP_CORE_H_INCLUDED_
#define _NGX_RTMP_CORE_H_INCLUDED_


#define NGX_RTMP_HOSTNAME_SUB      0x01
#define NGX_RTMP_HOSTNAME_PUB      0x02
#define NGX_RTMP_HOSTNAME_RTMP     0x04
#define NGX_RTMP_HOSTNAME_HTTP_FLV 0x08
#define NGX_RTMP_HOSTNAME_HLS      0x10


typedef struct {
    ngx_array_t             services; /* ngx_rtmp_core_svi_conf_t */

    ngx_msec_t              timeout;
    ngx_msec_t              ping;
    ngx_msec_t              ping_timeout;
    ngx_flag_t              so_keepalive;
    ngx_int_t               max_streams;

    ngx_uint_t              ack_window;

    ngx_int_t               chunk_size;
    ngx_pool_t             *pool;
    ngx_chain_t            *free;
    ngx_chain_t            *free_hs;
    size_t                  max_message;
    ngx_flag_t              play_time_fix;
    ngx_flag_t              publish_time_fix;
    ngx_flag_t              busy;
    size_t                  out_queue;
    size_t                  out_cork;
    ngx_msec_t              buflen;

    ngx_rtmp_conf_ctx_t    *ctx;

    unsigned                listen:1;
} ngx_rtmp_core_srv_conf_t;


typedef struct {
#if (NGX_PCRE)
    ngx_rtmp_regex_t          *regex;
#endif
    ngx_rtmp_core_svi_conf_t  *service;   /* virtual name server conf */
    ngx_uint_t                 mask;
    ngx_str_t                  name;
} ngx_rtmp_host_name_t;


#endif /* _NGX_RTMP_CORE_H_INCLUDED_ */