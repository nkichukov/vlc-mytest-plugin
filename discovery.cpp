/*****************************************************************************
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include <vlc_common.h>
#include <vlc_services_discovery.h>
#include <vlc_plugin.h>

static int OpenSD (vlc_object_t *);

VLC_SD_PROBE_HELPER("mytest", "MYTEST Module", SD_CAT_LAN )

vlc_module_begin ()
    add_submodule ()
    set_shortname( "MYTEST Module")
    set_description( "MyTest Protocol Discovery" )
    set_category (CAT_PLAYLIST)
    set_subcategory (SUBCAT_PLAYLIST_SD)
    set_capability ("services_discovery", 0)
    set_callbacks (OpenSD, NULL)
    add_shortcut ("mytest")

    VLC_SD_PROBE_SUBMODULE

vlc_module_end ()

const char *const cfg_options[] =
{
    "port",
    "host",
    "user",
    "pass",
    NULL
};

/**
 * Probes and initializes.
 */
static int OpenSD (vlc_object_t *obj)
{
    services_discovery_t *sd = (services_discovery_t *)obj;

    sd->description = "MYTEST Module";
    input_item_t *item;

//    input_item_SetName(item, name);
//    input_item_SetURI(item, url);

    char mrl[] = "file:///A:/", name[] = "A:";
    item = input_item_New(mrl, name);
    msg_Dbg (sd, "adding %s (%s)", mrl, name);
    services_discovery_AddItem(sd, item);


    char mrl2[] = "file:///B:/", name2[] = "B:";
    item = input_item_New(mrl2, name2);
    msg_Dbg (sd, "adding %s (%s)", mrl2, name2);
    services_discovery_AddItem(sd, item);
    
    return VLC_SUCCESS;
}
