namespace dragonBones
{

    /**
     * The DecompressedData is a convenient class for storing animation related data (data, atlas, object).
     *
     * @see dragonBones.Armature
     */
    class DecompressedData
    {
        public String textureBytesDataType;
        /**
         * A xml for DragonBones data.
         */
        public var dragonBonesData:Object;
        /**
         * A xml for atlas data.
         */
        public var textureAtlasData:Object;
        /**
         * The non parsed data map.
         */
        public ByteArray textureBytes;
        
        /**
         * Creates a new DecompressedData instance.
         * @param    xml A xml for DragonBones data.
         * @param    textureAtlasXML A xml for atlas data.
         * @param    textureBytes The non parsed data map.
         */
        public function DecompressedData(dragonBonesData:Object, textureAtlasData:Object, textureBytes:ByteArray)
        {
            this.dragonBonesData = dragonBonesData;
            this.textureAtlasData = textureAtlasData;
            this.textureBytes = textureBytes;
        }
        
        public function dispose():void
        {
            dragonBonesData = null;
            textureAtlasData = null;
            textureBytes = null;
        }
    }
}